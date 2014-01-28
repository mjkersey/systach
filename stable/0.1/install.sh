cd build/
cmake ../sources/ -DCMAKE_INSTALL_PREFIX=`kde4-config --prefix` -DCMAKE_BUILD_TYPE=debugfull
sudo make install
kbuildsycoca4
cd ..
