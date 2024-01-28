.. Core Utilities documentation master file, created by
   sphinx-quickstart
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to CPPSalt documentation!
=================================
Some time ago I started a C library titled `CSalt <https://csalt-lib.readthedocs.io/en/latest/>`_   
to develop a C library that priovided basic functionality and data structures for 
Plain Old Data (POD).  I decided that for completeness I needed to provide a 
similar library cor the C++ programming language.  However, C++ already has a robust
library that comes with most compilers titled the Standard Template Library (STL).
This library is not meant to replace STL, and in most instances mimics many features
of STL.  However, the development of this library has occurred to help the author
uncover the mechanisms and architecture of STL.  That said, in many instances, the 
library may modify the functionality or add to the funcitonality of STL.  The 
library described in this documentation is developed under the ``cslt`` namespace.

.. toctree::
   :maxdepth: 1
   :caption: Contents:

   dtype.h <DTypes>
   io.h <io>
   exceptions.h <Exception>
   util <Util>

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

Installation
============
This project is covered under a basic MIT license which allows anyone to use 
this code base or to contribute to it with the express permsission of the 
git project owner.

Use Code Base 
-------------
In order to download this repository from github, follow these instructions

#. Ensure you have ``.git`` installed on your computer

#. Ensure you have ``cmake`` installed on your computer.  This code-base requires 
   cmake version 3.27.7 or later versions.

#. Download this repository to your preferred directory with the following command;

   .. code-block:: bash 

      git clone https://github.com/Jon-Webb-79/cppsalt.git cppsalt 

#. Navigate to either the bash or zshell scripts directory depending on your 
   environment with one of the following commands.

   .. code-block:: bash 

      cd cppsalt/scripts/bash 
      cd cppsalt/scripts/zsh 

#. Build the code base with the following command.

   .. code-block:: bash 

      # If using bash
      bash build.sh  
      # If using zsh 
      zsh build.zsh

#. Compile the code base with the following command.

   .. code-block:: bash 

      # If using bash 
      bash compile.sh 
      # If using zsh 
      zsh compile.zsh

#. Navigate to ``cppsalt/cppsalt/build`` to run unit tests 

   .. code-block:: bash 

      valgrind ./unit_tests 
      
#. If all unit tests do not pass with no memory leaks, you may need to contact 
   the administrator of this git repository.  If they do pass, then you are set 
   to transform this code-base into a static or dynamic library, or just 
   copy the ``.c`` and ``.h`` files to your project.

Contribute to Code Base 
-----------------------
#. Establish a pull request with the git repository owner.

#. Once the package has been downloade, you will also need to install
   Python3.10 or later version to support documentation with Sphinx.

#. Navigate to the ``cppsalt/docs/doxygen`` directory.

#. Create a Python virtual environment with the following command.

   .. code-block:: bash 

      python -m venv .venv 

#. Activate the virtual environment with the following command.

.. table:: Activation Commands for Virtual Environments

   +----------------------+------------------+-------------------------------------------+
   | Platform             | Shell            | Command to activate virtual environment   |
   +======================+==================+===========================================+
   | POSIX                | bash/zsh         | ``$ source <venv>/bin/activate``          |
   +                      +------------------+-------------------------------------------+
   |                      | fish             | ``$ source <venv>/bin/activate.fish``     |
   +                      +------------------+-------------------------------------------+
   |                      | csh/tcsh         | ``$ source <venv>/bin/activate.csh``      |
   +                      +------------------+-------------------------------------------+
   |                      | Powershell       | ``$ <venv>/bin/Activate.ps1``             |
   +----------------------+------------------+-------------------------------------------+
   | Windows              | cmd.exe          | ``C:\> <venv>\\Scripts\\activate.bat``    |
   +                      +------------------+-------------------------------------------+
   |                      | PowerShell       | ``PS C:\\> <venv>\\Scripts\\Activate.ps1``|
   +----------------------+------------------+-------------------------------------------+

#. Install packages to virtual environments from ``requirements.txt`` file

   .. code-block:: bash 

      pip install -r requirements.txt

#. At this point you can build the files in the same way described in the 
   previous section and contribute to documentation.


Contributing
============
Pull requests are welcome.  For major changes, please open an issue first to discuss what
you would like to change.  Please make sure to include and update tests as well
as relevant cod-strings and sphinx updates.

License
=======
This project uses a basic MIT license
