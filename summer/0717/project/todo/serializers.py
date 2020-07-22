from .models import Todo

from rest_framework import serializers


class LevelsField(serializers.Field):
    def to_representation(self, value):
        return [value.level]

    def to_internal_value(self, data):
        return ','.join(data)


class TodoSerializer(serializers.ModelSerializer):
    key = serializers.IntegerField(source='id')
    levels = LevelsField(source='*')
    date = serializers.DateTimeField(source='created', format="%Y-%m-%d %H:%M", read_only=True)
    expd = serializers.BooleanField(default=True)

    class Meta:
        model = Todo
        fields = ['key', 'title', 'desc', 'levels', 'date', 'expd']
        