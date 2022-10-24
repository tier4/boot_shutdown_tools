# generated from rosidl_generator_py/resource/_idl.py.em
# with input from boot_shutdown_api_msgs:msg/EcuState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EcuState(type):
    """Metaclass of message 'EcuState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'UNKNOWN': 0,
        'STARTUP': 1,
        'RUNNING': 2,
        'SHUTDOWN_PREPARING': 3,
        'SHUTDOWN_READY': 4,
        'STARTUP_TIMEOUT': 1001,
        'SHUTDOWN_TIMEOUT': 1002,
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
                'boot_shutdown_api_msgs.msg.EcuState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ecu_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ecu_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ecu_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ecu_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ecu_state

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'UNKNOWN': cls.__constants['UNKNOWN'],
            'STARTUP': cls.__constants['STARTUP'],
            'RUNNING': cls.__constants['RUNNING'],
            'SHUTDOWN_PREPARING': cls.__constants['SHUTDOWN_PREPARING'],
            'SHUTDOWN_READY': cls.__constants['SHUTDOWN_READY'],
            'STARTUP_TIMEOUT': cls.__constants['STARTUP_TIMEOUT'],
            'SHUTDOWN_TIMEOUT': cls.__constants['SHUTDOWN_TIMEOUT'],
        }

    @property
    def UNKNOWN(self):
        """Message constant 'UNKNOWN'."""
        return Metaclass_EcuState.__constants['UNKNOWN']

    @property
    def STARTUP(self):
        """Message constant 'STARTUP'."""
        return Metaclass_EcuState.__constants['STARTUP']

    @property
    def RUNNING(self):
        """Message constant 'RUNNING'."""
        return Metaclass_EcuState.__constants['RUNNING']

    @property
    def SHUTDOWN_PREPARING(self):
        """Message constant 'SHUTDOWN_PREPARING'."""
        return Metaclass_EcuState.__constants['SHUTDOWN_PREPARING']

    @property
    def SHUTDOWN_READY(self):
        """Message constant 'SHUTDOWN_READY'."""
        return Metaclass_EcuState.__constants['SHUTDOWN_READY']

    @property
    def STARTUP_TIMEOUT(self):
        """Message constant 'STARTUP_TIMEOUT'."""
        return Metaclass_EcuState.__constants['STARTUP_TIMEOUT']

    @property
    def SHUTDOWN_TIMEOUT(self):
        """Message constant 'SHUTDOWN_TIMEOUT'."""
        return Metaclass_EcuState.__constants['SHUTDOWN_TIMEOUT']


class EcuState(metaclass=Metaclass_EcuState):
    """
    Message class 'EcuState'.

    Constants:
      UNKNOWN
      STARTUP
      RUNNING
      SHUTDOWN_PREPARING
      SHUTDOWN_READY
      STARTUP_TIMEOUT
      SHUTDOWN_TIMEOUT
    """

    __slots__ = [
        '_state',
        '_name',
        '_message',
        '_power_off_time',
    ]

    _fields_and_field_types = {
        'state': 'uint16',
        'name': 'string',
        'message': 'string',
        'power_off_time': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.state = kwargs.get('state', int())
        self.name = kwargs.get('name', str())
        self.message = kwargs.get('message', str())
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
        if self.state != other.state:
            return False
        if self.name != other.name:
            return False
        if self.message != other.message:
            return False
        if self.power_off_time != other.power_off_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'state' field must be an unsigned integer in [0, 65535]"
        self._state = value

    @property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

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
