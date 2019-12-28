
from django.db import models
from ManageApp import settings

class Memo(models.Model):
    id=models.AutoField(primary_key=True)
    title = models.CharField(max_length=100, blank=True, default='')
    body = models.TextField()
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE,)
    update_at = models.DateTimeField(auto_now=True)
    REQUIRED_FIELDS = ['title', 'body', 'user']

    def __str__(self):
        return self.title

