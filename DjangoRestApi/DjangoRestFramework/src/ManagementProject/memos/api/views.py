from rest_framework import status
from rest_framework.response import Response
from rest_framework.decorators import api_view, permission_classes
from rest_framework.permissions import IsAuthenticated

from accounts.models import Account
from memos.models import Memo
from memos.api.serializers import MemoSerializer

# get all memo of authenticated user
@api_view(['GET',])
@permission_classes((IsAuthenticated,))
def api_all_memo_view(request):
    user=request.user
    memos = Memo.objects.filter(user=user)
    if request.method == "GET":
        serializer = MemoSerializer(memos, many=True)
        return Response(serializer.data)

# get a special memo
@api_view(['GET',])
@permission_classes((IsAuthenticated,))
def api_get_memo_view(request, id):

    try:
        memo = Memo.objects.get(id=id)
    except Memo.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    user = request.user
    if memo.user != user:
        return Response({'response': "You don't have permission to show that."})
    if request.method == "GET":
        serializer = MemoSerializer(memo)
        return Response(serializer.data)

# update a special memo
@api_view(['PUT',])
@permission_classes((IsAuthenticated,))
def api_update_memo_view(request, id):

    try:
        memo = Memo.objects.get(id=id)
    except Memo.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    user=request.user
    if memo.user != user:
        return Response({'response':"You don't have permission to edit that."})
    if request.method == "PUT":
        serializer = MemoSerializer(memo,data=request.data)
        data={}
        if serializer.is_valid():
            serializer.save()
            data['success'] = "update successful"
            return Response(data=data)
        return Response(serializer.errors,status.HTTP_400_BAD_REQUEST)

# Delete special memo
@api_view(['DELETE',])
@permission_classes((IsAuthenticated,))
def api_delete_memo_view(request, id):

    try:
        memo = Memo.objects.get(id=id)
    except Memo.DoesNotExist:
        return Response(status=status.HTTP_404_NOT_FOUND)
    user = request.user
    if memo.user != user:
        return Response({'response': "You don't have permission to delete that."})
    if request.method == "DELETE":
        operation = memo.delete()
        data={}
        if operation:
            data['success'] = "delete successful"
        else:
            data['failure'] = "delete failed"
        return Response(data=data)

# create new memo of auth user
@api_view(['POST',])
@permission_classes((IsAuthenticated,))
def api_create_memo_view(request):

    user = request.user
    memo = Memo(user=user)
    if request.method == "POST":
        serializer = MemoSerializer(memo,data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data,status=status.HTTP_201_CREATED)
        return Response(serializer.errors,status.HTTP_400_BAD_REQUEST)
