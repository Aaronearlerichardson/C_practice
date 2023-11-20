#define PY_SSIZE_T_CLEAN
#include <numpy/arrayobject.h>
#include <Python.h>
#include <stdio.h>

PyObject *add(PyObject *self, PyObject *args)
{
    double a, b;
    if (!PyArg_ParseTuple(args, "dd", &a, &b))
        return NULL;
    return PyFloat_FromDouble(a + b);
};

//static PyObject *system(PyObject *self, PyObject *args)
//{
//    const char *command;
//    int sts;
//
//    if (!PyArg_ParseTuple(args, "s", &command))
//        return NULL;
//    sts = system(command);
//    return PyLong_FromLong(sts);
//};

static PyMethodDef SpamMethods[] = {
    {"add", add, METH_VARARGS, "add two numbers"},
//    {"system", system, METH_VARARGS, "execute a shell command"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef spam = {
    PyModuleDef_HEAD_INIT,
    "spam",
    "spam module",
    -1,
    SpamMethods
};

PyMODINIT_FUNC PyInit_spam(){
    printf("spam module imported\n");
    return PyModule_Create(&spam);
}
