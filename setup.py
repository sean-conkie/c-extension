from distutils.core import setup, Extension


def main():
    setup(
        name="fputs",
        version="1.0.0",
        description="Python interface for the fputs C library function",
        author="Sean Conkie",
        author_email="seanpconkie@yahoo.com",
        ext_modules=[Extension("fputs", ["src/fputsmodule.c"])],
    )


if __name__ == "__main__":
    main()
