#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

PyObject *add(PyObject *self, PyObject *args)
{
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
    return PyLong_FromLong(a + b);
};

static PyMethodDef SpamMethods[] = {
    {"add", add, METH_VARARGS, "add two numbers"},
    //{"system", system, METH_VARARGS, "execute a shell command"},
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

//PyObject *system(PyObject *self, PyObject *args)
//{
//    const char *command;
//    int sts;
//
//    if (!PyArg_ParseTuple(args, "s", &command))
//        return NULL;
//    sts = system(command);
//    return PyLong_FromLong(sts);
//};