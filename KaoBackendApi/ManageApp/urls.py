"""ManageApp URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from django.conf.urls import include
from scripts.trainer import *

urlpatterns = [
    path('admin/', admin.site.urls),
    # REST FRAMEWORK URLS
    path('api/accounts/', include('accounts.api.urls', 'accounts_api')),
    path('api/memos/', include('memos.api.urls', 'memos_api')),

]
# Importing Necessary lib for AI
print("###################################")
print("###  Importing OpenCV-3.4.4-py3 ###")
print("###################################")
print("")
import os

for path in ['/root/.virtualenvs/OpenCV-3.4.4-py3/bin', '/root/.virtualenvs/OpenCV-3.4.4-py3/lib/python35.zip',
             '/root/.virtualenvs/OpenCV-3.4.4-py3/lib/python3.5',
             '/root/.virtualenvs/OpenCV-3.4.4-py3/lib/python3.5/plat-x86_64-linux-gnu',
             '/root/.virtualenvs/OpenCV-3.4.4-py3/lib/python3.5/lib-dynload', '/usr/lib/python3.5',
             '/usr/lib/python3.5/plat-x86_64-linux-gnu',
             '/root/.virtualenvs/OpenCV-3.4.4-py3/lib/python3.5/site-packages',
             '/root/.virtualenvs/OpenCV-3.4.4-py3/lib/python3.5/site-packages/IPython/extensions',
             '/root/.ipython']:
    os.sys.path.append(path)
import cv2
import sys
import numpy as np
from PIL import Image
import os

# Print the current working directory
print(os.getcwd())

train_model()
