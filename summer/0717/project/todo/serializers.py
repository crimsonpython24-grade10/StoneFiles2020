from .models import Todo

from rest_framework import serializers


class TodoSerializer(serializers.ModelSerializer):
    key = serializers.IntegerField(source='id')
    levels = serializers.ListField(source='level')
    date = serializers.DateTimeField(source='created', format="%Y-%m-%d %H:%M", read_only=True)

    class Meta:
        model = Todo
        fields = ['key', 'title', 'desc', 'level', 'levels', 'date']
        