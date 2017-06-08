brew install openssl libuv cmake
brew install --force openssl
ln -s /usr/local/opt/openssl/lib/libcrypto.1.0.0.dylib /usr/local/lib/
ln -s /usr/local/opt/openssl/lib/libssl.1.0.0.dylib /usr/local/lib/
ln -s /usr/local/Cellar/openssl/1.0.2j/bin/openssl /usr/local/bin/openssl

git clone https://github.com/uWebSockets/uWebSockets
cd uWebSockets
git checkout e94b6e1
patch CMakeLists.txt < ../cmakepatch.txt
mkdir build
export PKG_CONFIG_PATH=/usr/local/opt/openssl/lib/pkgconfig
export OPENSSL_ROOT_DIR=/usr/local/Cellar/openssl/1.0.2l
cd build
cmake ..
make
sudo make install
cd ..
cd ..
sudo rm -r uWebSockets
