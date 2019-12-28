from django.urls import path
from memos.api.views import(
        api_get_memo_view,
        api_all_memo_view,
        api_create_memo_view,
        api_delete_memo_view,
        api_update_memo_view,

)

app_name="memos"
urlpatterns = [

      path('all',api_all_memo_view,name="all_memo"),
      path('<id>',api_get_memo_view,name="get_memo"),
      path('<id>/update',api_update_memo_view,name="update_memo"),
      path('<id>/delete', api_delete_memo_view, name="delete_memo"),
      path('create/', api_create_memo_view, name="create_memo"),
]