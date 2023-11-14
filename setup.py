from setuptools import setup, Extension

setup(
    name='spam',
    version='2.20',
    description='C parser in Python',
    ext_modules=[Extension('spam', ['spam.c'])]
)