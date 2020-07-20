from django.urls import path, include

from rest_framework import routers
from . import views


router = routers.DefaultRouter()
router.register(r'todos', views.TodoViewSet)

urlpatterns = [
    path('', views.IndexView.as_view(), name='todo_all'),
    path('api/', include(router.urls)),
]
