

def recognize():

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
    import numpy as np
    from PIL import Image

    print("###############################################")
    print("######  Face Recognizing  is starting... ######")
    print("###############################################")
    print("")

    # init id counter
    id_num = 0
    # init confidante
    confidence = 0

    recognizer = cv2.face.LBPHFaceRecognizer_create()
    recognizer.read('ai_models/trainer.yml')
    cascadePath = "ai_models/haarcascade_frontalface_default.xml"
    faceCascade = cv2.CascadeClassifier(cascadePath)
    font = cv2.FONT_HERSHEY_SIMPLEX

    # Read the image
    image = cv2.imread("images_db/test_subject/Ahmed_01.png")
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.2,
        minNeighbors=5,
        minSize=(30, int(30)),
    )
    for (x, y, w, h) in faces:
        cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
        id_num, confidence = recognizer.predict(gray[y:y + h, x:x + w])

        # If confidence is less them 100 ==> "0" : perfect match
        if confidence < 100:
            # id = names[id]
            confidence = "  {0}%".format(round(100 - confidence))
        else:
            id_num = "unknown"
            confidence = "  {0}%".format(round(100 - confidence))

        cv2.putText(
            image,
            str(id_num),
            (x + 5, y - 5),
            font,
            1,
            (255, 255, 255),
            2
        )
        cv2.putText(
            image,
            str(confidence),
            (x + 5, y + h - 5),
            font,
            1,
            (255, 255, 0),
            1
        )

    cv2.imwrite('/images_db/processed_img' + str(id_num) + '_' + '.png', image)

    # Do a bit of cleanup
    print("\n [INFO] Result: " + confidence)
    print("\n [INFO] Recognizing Ends")
