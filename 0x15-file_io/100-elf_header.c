#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
  * struct elf_header - Struct of elf_header
  *
  * @magic: Magic number
  * @class: Class of the ELF
  * @data: Data encoding
  * @version: ELF Version
  * @os_abi: OS/ABI identification
  * @abi_version: ABI Version
  * @type: Type of file
  * @entry_point: Entry point address
  */

typedef struct elf_header
{
	unsigned int magic;
	unsigned char class;
	unsigned char data;
	unsigned char version;
	unsigned char os_abi;
	unsigned char abi_version;
	unsigned short int type;
	unsigned int entry_point;
} elf_header_t;

/**
  * check_file - checks if the file is an ELF file
  * @filename: The name of the file
  *
  * Return: 1 if it is an ELF file, else 0
  */

int check_file(const char *filename)
{
	int fd;
	char buffer[4];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, buffer, 4);
	close(fd);
	if (buffer[0] != 0x7f && buffer[1] != 'E'
	    && buffer[2] != 'L' && buffer[3] != 'F')
		return (0);
	return (1);
}

/**
  * print_header - prints the ELF header information
  * @filename: The name of the file
  *
  * Return: 0 on success, else 1
  */

int print_header(const char *filename)
{
	int fd;
	elf_header_t elf_header;

	if (check_file(filename) == 0)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	read(fd, &elf_header, sizeof(elf_header_t));
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < 16; i++)
		printf("%02x ", ((unsigned char *)&elf_header.magic)[i]);
	printf("\n");
	printf("  Class:                             %c\n", elf_header.class);
	printf("  Data:                              %c\n", elf_header.data);
	printf("  Version:                           %x\n", elf_header.version);
	printf("  OS/ABI:                            %x\n", elf_header.os_abi);
	printf("  ABI Version:                       %x\n", elf_header.abi_version);
	printf("  Type:                              %hx\n", elf_header.type);
	printf("  Entry point address:               %x\n", elf_header.entry_point);

	close(fd);
	return (0);
}

/**
  * main - prints the ELF header information
  * @argc: The number of command line arguments
  * @argv: The array of command line arguments
  *
  * Return: 0 on success, else 1
  */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Error: Wrong number of arguments\n");
		exit(98);
	}
	if (print_header(argv[1]))
		return (1);
	return (0);
}
