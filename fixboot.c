#include <efivar/efivar.h>

uint32_t boot_attributes = EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS;

unsigned char bootorder_data[] = {
    0x06, 0x00, // Boot0006
    0x07, 0x00, // Boot0007
    0x08, 0x00, // Boot0008
    0x09, 0x00, // Boot0009
    0x0A, 0x00, // Boot000A
    0x0B, 0x00, // Boot000B
};

unsigned char boot0000_data[] = {
    0x00, 0x01, 0x00, 0x00, // Attributes
    0x18, 0x00,             // FilePathListLength

    // Description: "BIOS Setup       "
    0x42, 0x00, 0x49, 0x00, 0x4F, 0x00, 0x53, 0x00, 0x20, 0x00, 0x53, 0x00, 0x65, 0x00, 0x74, 0x00, 0x75, 0x00, 0x70, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
    0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00,

    // FilePathList[0]
    0x04,       // Type: Media Device Path
    0x06,       // Sub-Type: PIWG Firmware File
    0x14, 0x00, // Length: 4 + 0x14
    // SystemBiosSetupDxe (721c8b66-426c-4e86-8e99-3457c46ab0b9)
    0x66, 0x8B, 0x1C, 0x72, 0x6C, 0x42, 0x86, 0x4E, 0x8E, 0x99, 0x34, 0x57, 0xC4, 0x6A, 0xB0, 0xB9,

    // FilePathList[1]
    0x7F,       // Type: End of Hardware Device Path
    0xFF,       // Sub-Type: End Entire Device Path
    0x04, 0x00, // Length: 4

    // OptionalData (empty)
};

unsigned char boot0001_data[] = {
    0x00, 0x01, 0x00, 0x00, // Attributes
    0x18, 0x00,             // FilePathListLength

    // Description: "Boot Menu"
    0x42, 0x00, 0x6F, 0x00, 0x6F, 0x00, 0x74, 0x00, 0x20, 0x00, 0x4D, 0x00, 0x65, 0x00, 0x6E, 0x00, 0x75, 0x00, 0x00, 0x00,

    // FilePathList[0]
    0x04,       // Type: Media Device Path
    0x06,       // Sub-Type: PIWG Firmware File
    0x14, 0x00, // Length: 4 + 0x14
    // SystemBootMenuDxe (86488440-41bb-42c7-93ac-450fbf7766bf)
    0x40, 0x84, 0x48, 0x86, 0xBB, 0x41, 0xC7, 0x42, 0x93, 0xAC, 0x45, 0x0F, 0xBF, 0x77, 0x66, 0xBF,

    // FilePathList[1]
    0x7F,       // Type: End of Hardware Device Path
    0xFF,       // Sub-Type: End Entire Device Path
    0x04, 0x00, // Length: 4

    // OptionalData (empty)
};

int main() {
    int rc = efi_set_variable(EFI_GLOBAL_GUID, "BootOrder", bootorder_data, sizeof(bootorder_data), boot_attributes, 0644);
    if (rc < 0) {
        efi_error("Resetting BootOrder failed");
        return 1;
    }

    rc = efi_set_variable(EFI_GLOBAL_GUID, "Boot0000", boot0000_data, sizeof(boot0000_data), boot_attributes, 0644);
    if (rc < 0) {
        efi_error("Resetting Boot0000 failed");
        return 1;
    }

    rc = efi_set_variable(EFI_GLOBAL_GUID, "Boot0001", boot0001_data, sizeof(boot0001_data), boot_attributes, 0644);
    if (rc < 0) {
        efi_error("Resetting Boot0001 failed");
        return 1;
    }
}
