from setuptools import setup, Extension


# factory function
def my_build_ext(pars):
    # import delayed:
    from setuptools.command.build_ext import build_ext as _build_ext  #

    # include_dirs adjusted:
    class build_ext(_build_ext):
        def finalize_options(self):
            _build_ext.finalize_options(self)
            # Prevent numpy from thinking it is still in its setup process:
            import builtins; builtins.__NUMPY_SETUP__ = False
            import numpy
            self.include_dirs.append(numpy.get_include())

    # object returned:
    return build_ext(pars)

setup_args = dict(
    cmdclass={'build_ext' : my_build_ext},
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