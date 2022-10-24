# generated from rosidl_generator_py/resource/_idl.py.em
# with input from boot_shutdown_api_msgs:srv/PrepareShutdown.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PrepareShutdown_Request(type):
    """Metaclass of message 'PrepareShutdown_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('boot_shutdown_api_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'boot_shutdown_api_msgs.srv.PrepareShutdown_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__prepare_shutdown__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__prepare_shutdown__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__prepare_shutdown__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__prepare_shutdown__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__prepare_shutdown__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PrepareShutdown_Request(metaclass=Metaclass_PrepareShutdown_Request):
    """Message class 'PrepareShutdown_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_PrepareShutdown_Response(type):
    """Metaclass of message 'PrepareShutdown_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('boot_shutdown_api_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'boot_shutdown_api_msgs.srv.PrepareShutdown_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__prepare_shutdown__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__prepare_shutdown__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__prepare_shutdown__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__prepare_shutdown__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__prepare_shutdown__response

            from autoware_adapi_v1_msgs.msg import ResponseStatus
            if ResponseStatus.__class__._TYPE_SUPPORT is None:
                ResponseStatus.__class__.__import_type_support__()

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PrepareShutdown_Response(metaclass=Metaclass_PrepareShutdown_Response):
    """Message class 'PrepareShutdown_Response'."""

    __slots__ = [
        '_status',
        '_power_off_time',
    ]

    _fields_and_field_types = {
        'status': 'autoware_adapi_v1_msgs/ResponseStatus',
        'power_off_time': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['autoware_adapi_v1_msgs', 'msg'], 'ResponseStatus'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from autoware_adapi_v1_msgs.msg import ResponseStatus
        self.status = kwargs.get('status', ResponseStatus())
        from builtin_interfaces.msg import Time
        self.power_off_time = kwargs.get('power_off_time', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.power_off_time != other.power_off_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            from autoware_adapi_v1_msgs.msg import ResponseStatus
            assert \
                isinstance(value, ResponseStatus), \
                "The 'status' field must be a sub message of type 'ResponseStatus'"
        self._status = value

    @property
    def power_off_time(self):
        """Message field 'power_off_time'."""
        return self._power_off_time

    @power_off_time.setter
    def power_off_time(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'power_off_time' field must be a sub message of type 'Time'"
        self._power_off_time = value


class Metaclass_PrepareShutdown(type):
    """Metaclass of service 'PrepareShutdown'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('boot_shutdown_api_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'boot_shutdown_api_msgs.srv.PrepareShutdown')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__prepare_shutdown

            from boot_shutdown_api_msgs.srv import _prepare_shutdown
            if _prepare_shutdown.Metaclass_PrepareShutdown_Request._TYPE_SUPPORT is None:
                _prepare_shutdown.Metaclass_PrepareShutdown_Request.__import_type_support__()
            if _prepare_shutdown.Metaclass_PrepareShutdown_Response._TYPE_SUPPORT is None:
                _prepare_shutdown.Metaclass_PrepareShutdown_Response.__import_type_support__()


class PrepareShutdown(metaclass=Metaclass_PrepareShutdown):
    from boot_shutdown_api_msgs.srv._prepare_shutdown import PrepareShutdown_Request as Request
    from boot_shutdown_api_msgs.srv._prepare_shutdown import PrepareShutdown_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
