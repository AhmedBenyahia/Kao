from rest_framework import serializers
from accounts.models import Account
class RegistrationSerializer(serializers.ModelSerializer):

    password2 = serializers.CharField(style={'input_type': 'password'},write_only=True)

    class Meta:
        model = Account
        fields = ['id','first_name', 'last_name', 'email', 'password', 'password2']
        extra_kwargs ={
            'password': {'write_only':True}
        }
    def save(self):
         account = Account(
              first_name=self.validated_data['first_name'],
              last_name=self.validated_data['last_name'],
              email=self.validated_data['email'],
          )
         password = self.validated_data['password']
         password2 = self.validated_data['password2']

         if password != password2:
              raise serializers.ValidationError({'password':'Password must match'})
         account.set_password(password)
         account.save()
         return account

class UserDetailSerializer(serializers.ModelSerializer):
    class Meta:
        fields = (
            'id',
            'first_name',
            'last_name',
            'email',
            'password',
        )
        model =Account