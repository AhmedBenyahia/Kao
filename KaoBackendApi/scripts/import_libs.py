def hello():
    print("#############################")
    print("######  Welcome in Kao ######")
    print("#############################")
    print("")


def import_opencv():
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
