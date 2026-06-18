# Encrypt_Decrypt
<img width="2245" height="1587" alt="Before(1)" src="https://github.com/user-attachments/assets/f9d278f1-0058-49a2-8fa3-7b8b07a33675" />

A small, educational C program that demonstrates file-level encryption and decryption using a simple XOR cipher applied to each byte.

This tool reads a file in binary mode, XORs every byte with a single-byte numeric key (0–255), and writes the result to an output file. It is intended for learning and experimentation only — the algorithm is not secure for real-world use. See the Security section below.

---

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Build](#build)
- [Usage](#usage)
  - [Interactive mode](#interactive-mode)
  - [Non-interactive / scripting mode](#non-interactive--scripting-mode)
- [Example end-to-end demo](#example-end-to-end-demo)
- [Notes about the key and behavior](#notes-about-the-key-and-behavior)
- [Security](#security)
- [Possible improvements](#possible-improvements)
- [Testing](#testing)
- [License](#license)
- [Author](#author)

## Features

- Interactive prompts for:
  - input filename
  - output filename
  - numeric key (1–255)
- Binary-safe: opens files with `rb`/`wb`, so it works with text and binary files (images, executables, etc.).
- Simple, easy-to-read implementation using `fgetc`/`fputc` and a single-byte XOR operation.
- Clear error messages:
  - `Error: File not found!` if the input file can't be opened
  - `Error: Cannot create output file!` if the output file can't be created
- Success message and reminder to use the same key to decrypt.

## Requirements

- A C compiler (e.g., `gcc`, `clang`) that supports C99.
- A terminal (Linux/macOS) or Command Prompt / PowerShell (Windows).

## Build

Compile the program with gcc (example):

```sh
gcc -std=c99 -O2 -o encrypt_decrypt encrypt_decrypt.c
```

Replace `encrypt_decrypt.c` with the actual filename if different.

## Usage

This program is interactive — it asks for the input filename, output filename, and key when run.

### Interactive mode

Example interactive session:

```sh
$ ./encrypt_decrypt
=== FILE ENCRYPTION (XOR) ===

Enter input filename: plain.txt
Enter output filename: encrypted.bin
Enter key (number 1-255): 42

File encrypted successfully!
Run with the SAME key to decrypt
```

To decrypt, run the program again and provide `encrypted.bin` as input, a new output filename (e.g., `recovered.txt`), and the same key `42`.

### Non-interactive / scripting mode

You can supply the three inputs via STDIN if you want to script the operation (useful for demos or CI):

```sh
printf "plain.txt\nencrypted.bin\n42\n" | ./encrypt_decrypt
```

Or using a here-document:

```sh
./encrypt_decrypt <<EOF
plain.txt
encrypted.bin
42
EOF
```

## Example end-to-end demo

```sh
# Create a sample file
printf "Hello, XOR!\n" > plain.txt

# Encrypt
printf "plain.txt\nencrypted.bin\n42\n" | ./encrypt_decrypt

# Decrypt to a new file
printf "encrypted.bin\nrecovered.txt\n42\n" | ./encrypt_decrypt

# Compare (optional)
hexdump -C plain.txt
hexdump -C recovered.txt
```

## Notes about the key and behavior

- The program prompts: `Enter key (number 1-255)` — it expects an integer value. The code may not enforce the 1–255 range strictly; avoid `0` (XOR key 0 leaves bytes unchanged).
- XOR is symmetric: applying the same key twice returns the original data.
- The program exits with code `1` when it cannot open the input file or cannot create the output file.

## Security

- This implementation is educational only. A single-byte XOR key repeated across a file is extremely weak: it is vulnerable to frequency analysis, known-plaintext attacks, and simple statistical attacks.
- Do NOT use this for protecting real secrets or transmitting sensitive data.
- For real-world confidentiality, use established cryptographic libraries and algorithms (e.g., AES-GCM via libsodium or OpenSSL) with proper key management.

## Possible improvements

If you want to extend the program, consider:

- Accepting command-line flags (input, output, key) instead of interactive prompts.
- Validating the key range (reject or re-prompt on invalid input).
- Allowing multi-byte keys or reading a key from a file (e.g., use a passphrase-derived key).
- Generating a secure random key and saving it to a protected file.
- Adding progress reporting for large files and unit tests.
- Using a proper crypto library for real-world security requirements.

## Testing

- Add small automated tests for round-trip encryption/decryption using temporary files.
- Verify behavior on binary files (images, compressed files) as well as text files.
- Test error conditions (missing input file, unwritable output path, invalid key input).

## License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

## Author

Created by ImineAmazigh. For questions or suggested changes, open an issue or submit a pull request.
