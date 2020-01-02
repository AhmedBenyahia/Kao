def hello():
    print("#############################")
    print("######  Welcome in Kao ######")
    print("#############################")
    print("")


def test_env_1():
    print("#############################")
    print("###  Welcome in test_env_1 ##")
    print("#############################")
    print("")
    import os
    import cv2
    import sys
    import numpy as np
    from PIL import Image
    import os
    # Change the Current working Directory
    os.chdir('/root/kao/')
    # Get the current working directory
    os.getcwd()


def test_env_2():
    print("#############################")
    print("###  Welcome in test_env_2 ##")
    print("#############################")
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
    # Change the Current working Directory
    os.chdir('/root/kao/')
    # Get the current working directory
    os.getcwd()
