from rest_framework import status
from rest_framework.response import Response
from rest_framework.decorators import api_view, permission_classes
from rest_framework.permissions import IsAuthenticated
from rest_framework.permissions import AllowAny
from rest_framework.authtoken.views import ObtainAuthToken
from accounts.api.serializers import RegistrationSerializer
from accounts.api.serializers import UserDetailSerializer
from rest_framework import generics
from rest_framework import serializers
from rest_framework.authtoken.models import Token
from rest_framework.views import APIView
from accounts.models import Account

# login user and return auth token with user data
class CustomObtainAuthToken(ObtainAuthToken):
    def post(self, request, *args, **kwargs):
        response = super(CustomObtainAuthToken, self).post(request, *args, **kwargs)
        token = Token.objects.get(key=response.data['token'])
        user=Account.objects.get(id=token.user_id)
        serializer=UserDetailSerializer(user)
        return Response({'token': token.key,'user':serializer.data})

# user logout
class Logout(APIView):
    def get(self, request, format=None):
        # simply delete the token to force a login
        request.user.auth_token.delete()
        request.session.flush()
        return Response(status=status.HTTP_200_OK)

#registration user and return user with auth token
@api_view(['POST',])
@permission_classes((AllowAny,))
def registration_view(request):

        serializer = RegistrationSerializer(data=request.data)
        data = {}
        if serializer.is_valid():
            account = serializer.save()
            data['response']= "successfully registered a new user."
            data['id']=account.id
            data['first_name']=account.first_name
            data['last_name']=account.last_name
            data['email']=account.email
            token = Token.objects.get(user=account).key
            data['token'] = token

        else:
            data = serializer.errors
        return Response(data)

# get auth user
@api_view(['GET',])
@permission_classes((IsAuthenticated,))
def api_get_auth_user_view(request):
        user = request.user
        serializer=UserDetailSerializer(user)
        return Response(serializer.data)
