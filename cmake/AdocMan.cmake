#.adoc:
# Convert asciidoc to troff manual files adding a command to generate the file and creating a target for generating every single manpage
include(AddFileDependencies)

find_program(ADOCCOMMAND_PATH
  NAMES asciidoctor
  DOC "Path to AsciiDoc processor. Used to generate man pages from AsciiDoc."
)

if(NOT EXISTS ${ADOCCOMMAND_PATH})
  message(WARNING "AsciiDoc processor not found, man pages will not be generated. Install asciidoctor or use the CMAKE_PROGRAM_PATH variable.")
endif()

add_custom_target(man)

function(add_adoc_man FILENAME)
  if (NOT EXISTS ${ADOCCOMMAND_PATH})
    return()
  endif()
  set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/${FILENAME}.adoc)
  set(DST "${CMAKE_BINARY_DIR}/${FILENAME}")

  # Ensure destination directory exists
  get_filename_component(DEST_DIR ${DST} DIRECTORY)
  file(MAKE_DIRECTORY "${DEST_DIR}")

  add_custom_command(
    OUTPUT ${DST}
    COMMAND ${ADOCCOMMAND_PATH} -b manpage ${SRC} -o ${DST}
    DEPENDS ${SRC}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating man page ${DST}"
    VERBATIM
  )

  target_sources(man PRIVATE ${DST})
endfunction(add_adoc_man)
