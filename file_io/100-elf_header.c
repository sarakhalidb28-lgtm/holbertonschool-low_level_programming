#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_magic - prints magic bytes
 * @e_ident: ELF identifier
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i != EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * print_class - prints ELF class
 * @e_ident: ELF identifier
 */
void print_class(unsigned char *e_ident)
{
	printf("Class: ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints data encoding
 * @e_ident: ELF identifier
 */
void print_data(unsigned char *e_ident)
{
	printf("Data: ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version - prints ELF version
 * @e_ident: ELF identifier
 */
void print_version(unsigned char *e_ident)
{
	printf("Version: ");
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", e_ident[EI_VERSION]);
	else
		printf("%d\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - prints OS/ABI
 * @e_ident: ELF identifier
 */
void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI: ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * swap16 - swaps bytes of 16-bit value
 * @value: value to swap
 *
 * Return: swapped value
 */
unsigned int swap16(unsigned int value)
{
	return ((value >> 8) | (value << 8));
}

/**
 * swap64 - swaps bytes of 64-bit value
 * @value: value to swap
 *
 * Return: swapped value
 */
unsigned long int swap64(unsigned long int value)
{
	return (((value << 56) & 0xff00000000000000UL) |
		((value << 40) & 0x00ff000000000000UL) |
		((value << 24) & 0x0000ff0000000000UL) |
		((value << 8) & 0x000000ff00000000UL) |
		((value >> 8) & 0x00000000ff000000UL) |
		((value >> 24) & 0x0000000000ff0000UL) |
		((value >> 40) & 0x000000000000ff00UL) |
		((value >> 56) & 0x00000000000000ffUL));
}

/**
 * print_type - prints ELF type
 * @type: file type
 * @e_ident: ELF identifier
 */
void print_type(unsigned int type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		type = swap16(type);

	printf("Type: ");
	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}

/**
 * print_entry - prints entry point address
 * @entry: entry point value
 * @e_ident: ELF identifier
 */
void print_entry(unsigned long int entry, unsigned char *e_ident)
{
	printf("Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
		entry = swap64(entry);

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);
	else
		printf("%#lx\n", entry);
}

/**
 * main - displays the information contained in the ELF header
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close(fd);
	return (0);
}
