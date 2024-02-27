from fputs import fputs


def test_copy_data(tmpdir):
    content_to_copy = "Real Python!"
    bytes_copied = fputs(content_to_copy, f"{tmpdir}/test_write.txt")

    assert bytes_copied > 0

    with open(f"{tmpdir}/test_write.txt", "r") as f:
        content_copied = f.read()

    assert content_copied == content_to_copy
