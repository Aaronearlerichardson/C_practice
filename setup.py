from setuptools import setup, Extension

setup_args = dict(
    ext_modules=[
        Extension(
            'spam',
            ['spam.c',
             'helloworld/helloworld.cpp'],
            include_dirs=['helloworld'],
            py_limited_api=True
        )],
    name='spam',
    version='0.0.1',
    description='Python wrapper for spam'
)
setup(**setup_args)