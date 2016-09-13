
(function($) {
  
  Drupal.behaviors.punchclock = {
    attach: function(context, settings) {
      // Redirect if redirect property is set
      if (settings.punchclock_reload) {
        window.location.reload();
      }
    },
  };
  
}) (jQuery);
