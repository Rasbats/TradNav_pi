# finSAR_edit_pi

Compiling locally (Windows)
============================

#1 Run buildwin/win_deps.bat with the argument wx32 as Administrator.
_$win_deps.bat wx32_

This creates a cache folder containing wxWidgets-3.2.4 which will be compatible with OpenCPN 5.9.x/5.10.

#2 Run the batch file _leamas..finSAR_edit_pi.bat_.

This makes a _build_ folder and generates a Visual Studio solution file. This can be used for updates to the project. The batch
file continues and if there are no errors makes a tarball that can be imported into OpenCPN (5.9.x/5.10).