# Utilities

Some simple utility programs

Linux builds of all files are included. They use fairly generic code, so it should be possible to build for other platforms with a compiler of your choice.

## `bin2h`

This reads in a binary file and generates a C style header file containing a byte array in blocks of 256 bytes.

usage:
```./bin2h x.bin > x.h```

## `bin2forth`

This reads in a binary file and generates a FORTH CODE block using c, words.

usage:
```./bin2forth x.bin > x.fs```

## `bin2xor`

This reads in a binary file and generates an XOR checksum, as using in Jupiter ACE tape files. This can be useful for verifying damaged files, or fixing the checksum in patched files.

usage:
```./bin2xor x.bin```
