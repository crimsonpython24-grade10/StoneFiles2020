from .models import Todo

from rest_framework import serializers


class TodoSerializer(serializers.ModelSerializer):
    level_choices = [
        ('important', 'Important'),
        ('normal', 'Normal'),
        ('unimportant', 'Not important')
    ]
    title = serializers.CharField(max_length=50, trim_whitespace=True)
    desc = serializers.CharField(max_length=500, allow_blank=True)
    level = serializers.ChoiceField(choices=level_choices)
    created = serializers.DateTimeField()

    class Meta:
        model = Todo
        fields = ['title', 'desc', 'level', 'created']
        