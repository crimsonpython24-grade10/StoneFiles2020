from django.views.generic.base import TemplateView

from rest_framework import viewsets

from .models import Todo
from .serializers import TodoSerializer


class IndexView(TemplateView):
    template_name = "todo/index.html"


class TodoViewSet(viewsets.ModelViewSet):
    queryset = Todo.objects.get_queryset().order_by('id')
    serializer_class = TodoSerializer
