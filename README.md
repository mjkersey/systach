SysTach System Monitor
==============

SysTach is a skinnable system monitoring Plasmoid for KDE written in QML and C++. SysTach, like the original Superkaramba widget of the same name, is a sort of "IT for car guys" Plasmoid. It features a variety of gauges allowing a quick visual confirmation of system health and status, and allows you to monitor everything from temperatures to process stats.

Media
--------------

Videos of SysTach can be found here:

[Feature Overview](https://youtu.be/eLq7ZUDpTFQ)
[Demo #1](https://youtu.be/oNwBRE1MG1Q)
[Demo #2](https://youtu.be/Ebp64_89S5Q)

Installation
--------------

The following are required to build SysTach from source:

- KDE 4.2 or higher
- kdelibs5 dev
- CMake 2.6+
- GCC 4.8+
- QT 4.7+ dev

For example, on a Debian system: 

sudo apt-get install build-essential cmake kdelibs5-dev

When all dependencies are installed, you may build using build.sh in the root of the project, and install using either:

* install.sh, or 
* cd build && make install

Requires root privileges to install. If install.sh is used, it will prompt you for credentials. uninstall.sh uninstalls and cleans up configuration files.

Once installed, SysTach will be present in the "Add Widgets" dialog. At the current time, only Desktop Widgets are supported.

Themes
--------------

A tool for importing themes has not yet been implemented, however -

The themes are stored in the SysTach QML directory in the "themes/" folder. There are 3 main components to theming:

* theme.cfg - an INI file containing theme details
* images/ - the folder where images are stored
* resources/ - the resources folder

Documentation on these items will be published soon. For the moment, please using the themes packaged with SysTach as a template for creating your own themes.

Contributing
--------------

Theme documentation is currently limited to the theme files. They have to be created manually. If there is sufficient demand and contributors, a utility to create themes may be implemented.

History
--------------
TODO

License
--------------

This project is licensed under the GPL.