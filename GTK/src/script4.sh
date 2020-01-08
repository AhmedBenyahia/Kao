#!/bin/bash
cd src/
./soc 40.122.110.117 5000 POST "/api/accounts/login" "{ \"username\": \"$1\", \"password\": \"$2\" }" "Content-Type: application/json" && ./json_parser > Data.txt
echo "Http 200 OK"