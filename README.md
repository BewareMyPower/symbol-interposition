# symbol-interposition

This project demonstrate how the symbol interposition happens on **Linux** and how to prevent it by leveraging the `-Wl,-Bsymbolic` link option.

## Default

```bash
cmake -B build
cmake --build build
./build/main 0
```

As you can see, `bar()` returns 0 but not 12346. It shows when `bar()` calls `foo()`, the definition of `foo()` comes from the definition in `main.cc` that returns -1 in `main.cc`, not the definition in `foo.c` from the library (`libfoo.so`) that returns 12345.

## After add `-Wl,-Bsymbolic` as the link option

```bash
cmake -B build -DEXTRA_LINK_OPTIONS="-Wl,-Bsymbolic"
cmake --build build
./build/main 12346
```

After adding the `-Wl,-Bsymbolic` link option, the local definition of `foo()` in `libfoo.so` will be found.

## Reference

- [GCC Official Documents: Options for Linking](https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html)
- [MaskRay's Blog: ELF interposition and -Bsymbolic](https://maskray.me/blog/2021-05-16-elf-interposition-and-bsymbolic)
