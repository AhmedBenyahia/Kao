from django.db import models
from django.contrib.auth.models import (
    BaseUserManager, AbstractBaseUser
)
from django.conf import settings
from django.db.models.signals import post_save
from django.dispatch import receiver
from rest_framework.authtoken.models import Token


class MyAccountManager(BaseUserManager):
    def create_user(self, first_name, last_name, email, password=None):
        if not first_name:
            raise ValueError('users must have a first name')
        if not last_name:
            raise ValueError('users must have a first name')
        if not email:
            raise ValueError('Users must have an email address')
        user = self.model(
            first_name=first_name,
            last_name=last_name,
            email=self.normalize_email(email),
        )
        user.set_password(password)
        user.save(using=self._db)
        return user

    def create_superuser(self,first_name,last_name,email, password):
        user = self.create_user(
            first_name=first_name,
            last_name=last_name,
            email=self.normalize_email(email),
            password=password,
        )
        user.is_active = True
        user.is_admin = True
        user.is_staff = True
        user.save(using=self._db)
        return user


class Account(AbstractBaseUser):
    id=models.AutoField(primary_key=True)
    first_name = models.CharField(max_length=100, default='')
    last_name = models.CharField(max_length=100, default='')
    email = models.EmailField(verbose_name='email address', max_length=255, unique=True)
    created = models.DateTimeField(verbose_name='joined date', auto_now_add=True)
    is_active = models.BooleanField(default=True)
    is_staff = models.BooleanField(default=False)  # a admin user; non super-user
    is_admin = models.BooleanField(default=False)  # a superuser
    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = ['first_name', 'last_name']  # Email & Password are required by default.

    objects = MyAccountManager()

    def __str__(self):
        return self.email

    # For checking permissions. to keep it simple all admin have ALL permissons
    def has_perm(self, perm, obj=None):
        return self.is_admin

    # Does this user have permission to view this app? (ALWAYS YES FOR SIMPLICITY)
    def has_module_perms(self, app_label):
        return True

@receiver(post_save, sender=settings.AUTH_USER_MODEL)
def create_auth_token(sender, instance=None, created=False, **kwargs):
    if created:
        Token.objects.create(user=instance)