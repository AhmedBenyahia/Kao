from django.urls import path
from accounts.api.views import(
        registration_view,
        CustomObtainAuthToken,
        api_get_auth_user_view,
        Logout,
        api_upload_image_file,
        api_get_user_view,


)

app_name="accounts"

urlpatterns = [
      path('register',registration_view,name="register"),
      path('login', CustomObtainAuthToken.as_view(), name="login"),
      path('auth', api_get_auth_user_view, name="get_auth"),
      path('logout', Logout.as_view(), name="logout"),
      path('upload', api_upload_image_file, name="upload"),
      path('face-login',api_get_user_view, name="face-login"),


]