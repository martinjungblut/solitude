#!/usr/bin/env bash
set -uo pipefail

BIN=${1:?Usage: $0 ./binary [args...]}
shift || true

"$BIN" "$@"
rc=$?

if [ "$rc" -eq 134 ]; then
  echo "[!] detected SIGABRT from $BIN"

  echo "[*] generating gdb backtrace (gdb-log.txt)..."
  gdb -q -batch \
      -ex "set pagination off" \
      -ex "run" \
      -ex "bt full" \
      -ex "info registers" \
      -ex "x/16i \$pc-8" \
      --args "$BIN" "$@" 2>&1 | tee gdb-log.txt
fi
