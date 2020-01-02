
def train_model():
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

    # function to get the images and label data
    def getImagesAndLabels(path):
        imagePaths = [os.path.join(path, f) for f in os.listdir(path)]
        faceSamples = []
        ids = []
        for imagePath in imagePaths:
            PIL_img = Image.open(imagePath).convert('L')  # grayscale
            img_numpy = np.array(PIL_img, 'uint8')
            id = int(os.path.split(imagePath)[-1].split("_")[0])
            faces = detector.detectMultiScale(img_numpy)
            for (x, y, w, h) in faces:
                faceSamples.append(img_numpy[y:y + h, x:x + w])
                ids.append(id)
        return faceSamples, ids

    # Print the current working directory
    print(os.getcwd())
    print("############################################")
    print("######  Training model is starting... ######")
    print("############################################")
    print("")
    # Path for image database
    path = 'images_db/'
    recognizer = cv2.face.LBPHFaceRecognizer_create()
    detector = cv2.CascadeClassifier("ai_models/haarcascade_frontalface_default.xml")

    print("\n [INFO] Training faces. It will take a few seconds. Wait ...")
    faces, ids = getImagesAndLabels(path)
    # print("faces,ids: ",faces,ids)
    recognizer.train(faces, np.array(ids))
    # Save the model into trainer/trainer.yml
    recognizer.write('ai_models/trainer.yml')
    # Print the numer of faces trained and end program
    print("\n [INFO] {0} faces trained. Exiting Program".format(len(np.unique(ids))))
