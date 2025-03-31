import ctypes


def calc_fibs(n: int):
    lib = ctypes.CDLL('./task.so')
    _calc_fibs = lib.calc_fibs
    _calc_fibs.argtypes = (ctypes.c_size_t, ctypes.POINTER(ctypes.c_longlong))
    _calc_fibs.restype = None
    src = (ctypes.c_longlong * n)()
    _calc_fibs(n, src)
    return list(src)


def make_uniq(array: list):
    lib = ctypes.CDLL('./task.so')
    _make_uniq = lib.make_uniq
    _make_uniq.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, ctypes.POINTER(
        ctypes.c_int), ctypes.POINTER(ctypes.c_size_t))
    _make_uniq.restype = ctypes.c_int
    src_n = len(array)
    src = (ctypes.c_int * src_n)(*array)
    dst_n = ctypes.c_size_t(0)
    rc = _make_uniq(src, src_n, None, dst_n)
    if rc:
        dst = (ctypes.c_int * dst_n.value)()
        rc = _make_uniq(src, src_n, dst, dst_n)
        return rc, list(dst)
    else:
        return rc, list()