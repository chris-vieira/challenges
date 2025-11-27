SUMMARY = "Simple C++ JSON parser using curl and nlohmann::json"
DESCRIPTION = "A test application to demonstrate how to create a recipe \
               by directly compiling C++ files with BitBake."

SECTION  = "examples"
PRIORITY = "optional"
RDEPENDS = curl libcurl

LICENSE = "MIT"
LIC_FILES_CHKSUM = "\
   file://LICENSE.txt;md5=07c86f5262ad9568188fd253af079f4d"

SRC_URI = "https://github.com/chris-vieira/challenges/blob/master/control-id/control-id_jsonp/control-id_jsonp.cpp \
           https://github.com/chris-vieira/challenges/blob/master/control-id/control-id_jsonp/json.hpp \
           https://github.com/chris-vieira/challenges/blob/master/control-id/README.md"

S = "${WORKDIR}"

TARGET_CFLAGS += "--std=c++14 -Wall -Wextra"
TARGET_LDFLAGS += ""

do_compile() {
    ${CXX} ${CFLAGS} ${LDFLAGS} -o control-id_jsonp control-id_jsonp.cpp -lcurl
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 control-id_jsonp ${D}${bindir}
}
