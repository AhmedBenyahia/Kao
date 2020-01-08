#!/bin/bash
cd src/
img64=`cat img.b64`
./soc 40.122.110.117 5000 POST "/api/accounts/face-login" "{ \"data\": \"$img64\" }" "Content-Type: application/json"
 ./json_parser  > Data.txt
#echo "./soc 40.122.110.117 5000 POST \"/api/accounts/face-login\" \"{ \"data\": \"$img64\" }\" \"Content-Type: application/json\" && ./json_parser  > Data.txt"
echo "Http 200 OK"