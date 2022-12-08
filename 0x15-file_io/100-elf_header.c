#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define ELF_MAGIC 0x464c457f
#define ELF_CLASS_32 0x1
#define ELF_CLASS_64 0x2
#define ELF_DATA_LSB 0x1
#define ELF_DATA_MSB 0x2
#define ELF_VERSION 0x1

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
typedef struct {
    char magic[4];
    char class;
    char data;
    char version;
    char os_abi;
    char abi_version;
    char type[2];
    char entry_point[4];
} Elf_hdr;

void print_error(char *message);

int main(int argc, char **argv) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename\n");
    }

    // Open file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Error: could not open file.\n");
    }

    // Read ELF header
    Elf_hdr elf_hdr;
    if (read(fd, &elf_hdr, sizeof(Elf_hdr)) != sizeof(Elf_hdr)) {
        print_error("Error: could not read ELF header.\n");
    }

    // Check for ELF magic number
    int magic = 0;
    for (int i = 0; i < 4; i++) {
        magic = (magic << 8) | elf_hdr.magic[i];
    }
    if (magic != ELF_MAGIC) {
        print_error("Error: not an ELF file.\n");
    }

    // Print ELF header
    printf("ELF Header\n");
    printf("Magic: \t\t\t");
    for (int i = 0; i < 4; i++) {
        printf("%02x ", elf_hdr.magic[i]);
    }
    printf("\n");
    printf("Class: \t\t\t");
    if (elf_hdr.class == ELF_CLASS_32) {
        printf("ELF32\n");
    } else if (elf_hdr.class == ELF_CLASS_64) {
        printf("ELF64\n");
    } else {
        print_error("Error: invalid class.\n");
    }
    printf("Data: \t\t\t");
    if (elf_hdr.data == ELF_DATA_LSB) {
        printf("2's complement, little endian\n");
    } else if (elf_hdr.data == ELF_DATA_MSB) {
        printf("2's complement, big endian\n");
    } else {
        print_error("Error: invalid data encoding.\n");
    }
    printf("Version: \t\t");
    if (elf_hdr.version == ELF_VERSION) {
        printf("1 (current)\n");
    } else {
        print_error("Error: invalid version.\n");
    }
    printf("OS/ABI: \t\t");
    printf("UNIX - System V\n");
    printf("ABI Version: \t\t");
    printf("0\n");
    printf("Type: \t\t\t");
    if (elf_hdr.type[0] == 0x1 && elf_hdr.type[1] == 0x2) {
        printf("EXEC (Executable file)\n");
    } else {
        print_error("Error: invalid type.\n");
    }
    printf("Entry point address: \t");
    int entry_point = 0;
    for (int i = 0; i < 4; i++) {
        entry_point = (entry_point << 8) | elf_hdr.entry_point[i];
    }
    printf("0x%x\n", entry_point);

    return 0;
}

void print_error(char *message) {
    fprintf(stderr, "%s", message);
    exit(98);
}
