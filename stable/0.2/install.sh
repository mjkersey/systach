cd build/
cmake ../sources/ -DCMAKE_INSTALL_PREFIX=`kde4-config --prefix` -DCMAKE_BUILD_TYPE=release -DQT_QMAKE_EXECUTABLE=/usr/bin/qmake-qt4
sudo make install
kbuildsycoca4 2>/dev/null
cd ..




