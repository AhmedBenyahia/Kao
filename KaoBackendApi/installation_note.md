
# Create new python environment
## (normal installation) In The project root dir run:
sudo apt-get update && \
sudo apt-get install -y python-virtualenv && \
mkdir env && virtualenv -p /usr/bin/python3 env/djangoApi && \
source env/djangoApi/bin/activate && \
pip3 install -r requirements.txt


## (within the opencv docker container) In The project root dir run:
mkvirtualenv django-2.2.9 && \
pip3 install -r requirements.txt

#Install migration and Run the server 
python3 manage.py makemigrations && \  
python3 manage.py migrate && \
python manage.py createsuperuser && \
python3 manage.py runserver && \

# To import a new script from any directory in this project 
# i'm create file script.py exist in recognition_test so run this command 
export PYTHONPATH=$PYTHONPATH:your_directory/Kao/recognition-test




# Description 

//make all migration => python3 manage.py makemigrations 
//make all settings migrations => python3 manage.py migrate
//Run server=>python3 manage.py run server
// Create super user for admin managing in http://127.0.0.1:8000/admin/ => python manage.py createsuperuser


# APIs URLs
URL REGISTRATION ACCOUNT (http://127.0.0.1:8000/api/accounts/register);
URL LOGIN WITH TOKEN AUTHENTICATION (http://127.0.0.1:8000/api/accounts/login);
URL LOGIN WITH FACE RECOGNITION (http://127.0.0.1:8000/api/accounts/face-login)
URL LOGOUT WITH DELETE AUTH TOKEN (http://127.0.0.1:8000/api/accounts/logout);
URL GET AUTH USER (http://127.0.0.1:8000/api/accounts/auth);
URL UPLOAD FILES (http://127.0.0.1:8000/api/accounts/upload);
URL ALL MEMOS OF AUTH USER (http://127.0.0.1:8000/api/memos/all);
URL GET SPECIAL MEMO (http://127.0.0.1:8000/api/memos/{dynamique_id});
URL UPDATE SPECIAL MEMO (http://127.0.0.1:8000/api/memos/{dynamique_id}/update);
URL DELETE SPECIAL MEMO (http://127.0.0.1:8000/api/memos/{dynamique_id}/delete);
URL CREATE NEW MEMO (http://127.0.0.1:8000/api/memos/create);


