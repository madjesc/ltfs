#pragma once
/**
 * Message header definition for TAPE module
 * range: 39800 - 39999
 */

#define W39800 "Unsupported SCSI OP code 0x%02x."
#define D39801 "SCSI timeout (op_code 0x%02x, timeout = %d)."
#define W39802 "Unknown SCSI OP code 0x%02x, use default timeout."
#define E39803 "CRC check failed: Len = %d, Actual CRC = %08x, Expected CRC = %08x."
#define D39804 "CRC: %s ,Len = %d, CRC = %08x."
#define W39805 "The timeout table is not configured: SCSI OP code 0x%02x. Use the default timeout."
#define D39806 "Is medium mountable: six-character bar code %s."
#define E39807 "Is medium mountable: invalid bar code %s."
#define I39808 "Is medium mountable: unsupported medium %s is detected."
#define D39809 "WORM cartridge is loaded."
#define W39810 "No IP address was found. Use host name based reservation key."
#define W39811 "Cannot fetch network I/F information. Use host name based reservation key. (%d)"
#define W39812 "Drive firmware must be updated. Upgrading to %s or later is recommended."
#define W39813 "Drive firmware level does not correctly detect the EOD status."
