# Encrypt_Decrypt

A simple C program that demonstrates encrypting and decrypting text using the XOR cipher (character-by-character).

> NOTE: This project is intended for learning and demonstration only. The XOR cipher is not secure for real-world use unless implemented with proper one-time-pad practices.

## Features

- Encrypts plain text using a single-byte key (XOR operation on each character).
- Decrypts ciphertext using the same key.
- Minimal, easy-to-read C code suitable for beginners learning about bitwise operations and basic cryptography concepts.

## Requirements

- A C compiler (gcc, clang, or any standards-compliant C compiler).
- A Unix-like shell or Windows command prompt.

## Build

Compile the program with gcc:

```sh
gcc -o xor_cipher main.c
```

Replace `main.c` with the source file name used in this repository if different.

## Usage

Basic usage (example):

```sh
# Encrypt
./xor_cipher encrypt "Hello, world!" 42 > encrypted.bin

# Decrypt
./xor_cipher decrypt encrypted.bin 42
```

- The second argument is the key (an integer value between 0 and 255). The same key must be used to decrypt the output.
- If your program reads from stdin or writes to stdout, you can pipe data or redirect files as shown above.

## Example

Given the input `"ABC"` and key `1`, the encryption XORs each character with 1. Decrypting the result with the same key returns the original text.

## How it works (short)

XOR is a bitwise operation that has the property:

A XOR B XOR B = A

This makes XOR suitable for simple symmetric encryption: applying the same single-byte key twice returns the original byte. The program applies XOR to each byte of the input with the provided key to produce ciphertext; applying XOR again with the same key recovers the plaintext.

## Security note

XOR with a single repeating key is vulnerable to frequency analysis and other attacks. Do not use this approach to protect sensitive data. For real-world encryption use well-vetted algorithms and libraries (AES, libsodium, OpenSSL, etc.).

## Contributing

Contributions are welcome. Please open an issue or a pull request with a clear description of the change.

Ideas for improvements:

- Add support for multi-byte keys or key files.
- Add command-line flags for input/output files, key parsing, and different modes.
- Add unit tests and example test vectors.

## License

This repository is provided under the MIT License. See LICENSE for details (or add an appropriate license file).

## Contact

Created by ImineAmazigh. For questions or feedback, open an issue or contact via GitHub.
