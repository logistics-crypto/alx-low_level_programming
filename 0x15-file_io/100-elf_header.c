#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

int main(int argc, char **argv) {
    if (argc != 2) {
      print_error("Invalid number of arguments");
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        print_error("Failed to open file");
    }

    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        print_error("Failed to read ELF header");
    }

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || 
        elf_header.e_ident[EI_MAG1] != ELFMAG1 || 
        elf_header.e_ident[EI_MAG2] != ELFMAG2 || 
        elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        print_error("File is not an ELF file");
    }

    printf("Magic: %02x %02x %02x %02x\n", elf_header.e_ident[EI_MAG0], elf_header.e_ident[EI_MAG1],
	   elf_header.e_ident[EI_MAG2], elf_header.e_ident[EI_MAG3]);
    printf("Class: %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("Data: %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ?
	   "2's complement,little endian" : "2's complement, big endian");
    printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);
    printf("OS/ABI: %s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV ?
	   "UNIX System V ABI" : (elf_header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "Linux ABI" : "Other"));
    printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("Type: %s\n", elf_header.e_type == ET_REL ?
	   "Relocatable file" : (elf_header.e_type == ET_EXEC ?
				 "Executable file" : (elf_header.e_type == ET_DYN ? "Shared object file" : "Other")));
    printf("Entry point address: 0x%lx\n", elf_header.e_entry);

    close(fd);
    return 0;
}
