from rest_framework import serializers
from memos.models import Memo


class MemoSerializer(serializers.ModelSerializer):
    class Meta:
        model = Memo
        fields = ['id','title', 'body', 'user', 'update_at']
        extra_kwargs = {'user': {'required': False}}
