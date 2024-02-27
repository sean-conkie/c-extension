#include <Python.h>

static PyObject *StringTooShortError = NULL;

static PyObject *method_fputs(PyObject *self, PyObject *args){
  char *str, *filename = NULL;
  int bytes_written = -1;

  if (!PyArg_ParseTuple(args, "ss", &str, &filename)) {
    return NULL;
  }

  if (strlen(str) < 10) {
      PyErr_SetString(StringTooShortError, "String length must be greater than 10");
      return NULL;
  }

  FILE *fp = fopen(filename, "w");
  bytes_written = fputs(str, fp);
  fclose(fp);

  return PyLong_FromLong(bytes_written);
  
}

static PyMethodDef FputsMethods[] = {
  {"fputs", method_fputs, METH_VARARGS, "Python interface for fputs C library function"},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef fputsmodule = {
  PyModuleDef_HEAD_INIT,
  "fputs",
  "Python interface for the fputs C library function",
  -1,
  FputsMethods
};

PyMODINIT_FUNC PyInit_fputs(void) {

    /* Assign module value */
    PyObject *module = PyModule_Create(&fputsmodule);

    /* Initialize new exception object */
    StringTooShortError = PyErr_NewException("fputs.StringTooShortError", NULL, NULL);

    /* Add exception object to your module */
    PyModule_AddObject(module, "StringTooShortError", StringTooShortError);

    /* Add int constant by name */
    PyModule_AddIntConstant(module, "FPUTS_FLAG", 64);

    /* Define int macro */
    #define FPUTS_MACRO 256

    /* Add macro to module */
    PyModule_AddIntMacro(module, FPUTS_MACRO);
    
    return module;
}