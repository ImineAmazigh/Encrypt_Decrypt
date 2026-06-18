# Encrypt_Decrypt

A small, interactive C program (encrypt_decrypt.c) that demonstrates file-level encryption and decryption using a simple XOR cipher applied to each byte.

This program is designed for learning and experimentation: it reads a file in binary mode, XORs every byte with a single-byte numeric key (0–255), and writes the result to an output file. Running the program again on the ciphertext with the same key restores the original file.

Warning: XOR with a single-byte repeating key is not secure for protecting real data. See the Security section below.

---

## Features (what encrypt_decrypt.c does)

- Interactive prompts for:
  - input filename
  - output filename
  - numeric key (1–255)
- Binary-safe: opens files with `rb`/`wb`, so it works with text and binary files (images, executables, etc.).
- Simple, easy-to-read implementation using fgetc/fputc and a single-byte XOR operation.
- Clear error messages on failure:
  - "Error: File not found!" if the input file can't be opened
  - "Error: Cannot create output file!" if the output file can't be created
- Prints a success message and a reminder to use the same key to decrypt:
  - "File encrypted successfully!"
  - "Run with the SAME key to decrypt"

## Requirements

- A C compiler (gcc, clang, or any standards-compliant C compiler).
- A terminal (Linux/macOS) or Command Prompt / PowerShell (Windows).

## Build

Compile the program with gcc (example):

```sh
gcc -std=c99 -O2 -o encrypt_decrypt encrypt_decrypt.c
```

Replace `encrypt_decrypt.c` with the actual filename if different.

## Usage

This program is interactive — it asks for the input filename, output filename, and key when run.

Example interactive session:

$ ./encrypt_decrypt
=== FILE ENCRYPTION (XOR) ===

Enter input filename: plain.txt
Enter output filename: encrypted.bin
Enter key (number 1-255): 42

File encrypted successfully!
Run with the SAME key to decrypt

To decrypt, run the program again and provide `encrypted.bin` as input, a new output filename (e.g., `recovered.txt`), and the same key `42`.

Non-interactive automation

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

Example end-to-end demo

```sh
# Create a sample file
printf "Hello, XOR!\n" > plain.txt

# Encrypt
printf "plain.txt\nencrypted.bin\n42\n" | ./encrypt_decrypt

# Decrypt to a new file
printf "encrypted.bin\nrecovered.txt\n42\n" | ./encrypt_decrypt

# Compare
hexdump -C plain.txt
hexdump -C recovered.txt
```

## Notes about key and behavior

- The program prompts: "Enter key (number 1-255)" — it expects an integer value. The code does not enforce the 1–255 range, so avoid 0 (XOR key 0 leaves bytes unchanged).
- The XOR operation is symmetric: applying the same key twice returns the original data.
- The program exits with code 1 when it cannot open the input file or cannot create the output file.

## Security

- This implementation is educational only. A single-byte XOR key repeated across a file is extremely weak: it is vulnerable to frequency analysis, known-plaintext attacks, and simple statistical attacks.
- Do NOT use this for protecting real secrets or transmitting sensitive data.
- For real-world confidentiality use established cryptographic libraries and algorithms (e.g., AES-GCM via libsodium or OpenSSL), with proper key management.

## Possible improvements

If you want to extend the program, consider:

- Accepting command-line flags (input, output, key) instead of interactive prompts.
- Validating the key range and rejecting invalid input.
- Allowing multi-byte keys or reading a key from a file.
- Generating a random key and saving it to a protected key file (or printing a hex key) for one-time-pad style usage.
- Adding progress reporting for large files and unit tests.
- Using a proper crypto library if you need security guarantees.

## License

If you want to license this code, add a LICENSE file (e.g., MIT) to the repository. By default there is no license in the repo, which means others cannot legally reuse the code.

## Author

Created by ImineAmazigh. For questions or suggested changes, open an issue or submit a pull request.
