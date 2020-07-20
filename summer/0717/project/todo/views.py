from django.views.generic.base import TemplateView

from rest_framework import viewsets

from .models import Todo
from .serializers import TodoSerializer


class IndexView(TemplateView):
    template_name = "todo/index.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['todos'] = Todo.objects.all()
        return context


class TodoViewSet(viewsets.ModelViewSet):
    queryset = Todo.objects.all()
    serializer_class = TodoSerializer
