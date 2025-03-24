cd build-output
cmake -LAH ../ > ~/edgetx-cmake-options.txt
cmake -DPCB=X10 -DPCBREV=TX16S -DDEFAULT_MODE=2 -DGVARS=YES -DPPM_UNIT=US -DLUA_MIXER=YES -DCMAKE_BUILD_TYPE=Debug ../
make configure
make -j`nproc` firmware
